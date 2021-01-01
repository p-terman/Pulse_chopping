% function [result_cells query_time url_alive] = LUGQuery(query_string,xmlsettings)
%
%   Generic LUG field reader
%
% Inputs:
%       query string    - cell array with SQL statements (don't use ;)
%                       - first SQL statement must be 'use lug'
%                       - must be cleaned up by String_Replacement_Table
%                       - example:
%                            query_string = {'use lug',...
%                                            'select * from gas_type'}
%       xml_settings    - MySQL connection settings.
%                       - default generated by XMLReader('defaultLUGSettings.xml')
%                       - fields:
%                            - php_url
%                            - hostname
%                            - username
%                            - password
%
% Outputs:
%       result_cells    - string with MySQL query results FOR EACH entry in
%                         the query_string (including 'use lug')
%       query_time      - total live time of query
%       url_live        - 1 if url is live, 0 otherwise
%
%
% 20090511 CHF - Created
%
function [result_cells query_time url_alive] = LUGQuery(query_string,xmlsettings)
%% set defaults
result_cells = {};
query_time = -1;
url_alive = 0;
password = xmlsettings.password;
username = xmlsettings.username;
hostname = xmlsettings.hostname;
php_url  = xmlsettings.php_url;

%% translate cell array into single string of queries
if iscellstr(query_string)
    query_string_cells = query_string;
    query_string = query_string_cells{1};
    for n=2:length(query_string_cells)
        query_string = sprintf('%s;\n%s',query_string,query_string_cells{n});
    end;
    query_string = [query_string ';'];
end;

%% translate query string to post-safe character set

query_string = String_Replacement_Table(query_string);

%% post query
post_params={'hostname',hostname, ...
    'username',username, ...
    'password',password, ...
    'myquery',query_string};

tic;
[result_string url_success] = urlread(php_url,'post',post_params);
query_time = toc;

if ~url_success
    error('Could not reach LUG')
else
    url_alive = 1;
end

%% parse result
celldividers = [0 find(int8(result_string)==13)];
result_cells = cell(length(celldividers)-1,1);
for n = 1:length(result_cells)
    result_cells{n} = result_string((celldividers(n)+1):(celldividers(n+1)-1));
end


