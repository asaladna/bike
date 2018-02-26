# bike
# bike


Bike1
bb127acf-7732-429c-9b41-c867f9a9878e
Bike2
ea517841-d673-4e49-8308-d1dffd23b065

[Unit]
Description=Get IMS service running at boot
After = multi-user.target

[Service]
Type=idle
ExecStart = /usr/bin/python /home/pi/Desktop/bike/Reader.py
Restart = always
StandardOutput=syslog
StandardError=syslog
SyslogIdentifier=IMS


[Install]
WantedBy=multi-user.target
