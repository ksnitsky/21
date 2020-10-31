ifconfig | grep "ether" | sed -e 's/ether//g' -e 's/^[[:space:]]*//'
