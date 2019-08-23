##################################################
# File Name: /Users/hu/c_test/git.sh
# Author: panghu
# mail: panghuvpn@gmail.com
# Created Time: 2019-08-23/09:50:40
##################################################
#!/bin/bash



git add .
if [ -n "$1" ]; then
    git commit -m '$1'
else
    git commit -m 'update'
fi

git push origin master
