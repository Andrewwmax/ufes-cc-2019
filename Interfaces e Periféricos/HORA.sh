#!/bin/bash

#*********************************************************************#
# Antes de executar ./run.sh você deve dar perminsão para o arquivo   #
# possa ser executado. Para isso, execute o seginte comando:          #
#              chmod +x run.sh                                        #
#*********************************************************************#

hora=$(date +"%s")
# echo $hora
hora=`expr $hora - 10800`

echo $hora | xclip -selection clipboard
