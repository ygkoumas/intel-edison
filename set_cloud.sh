#run this before
#chmod 777 set_cloud.sh

#then substitute activation code and run the script.

systemctl stop iotkit-agent;

iotkit-admin activate <Activation_Code>;

iotkit-admin register wake powerswitch.v1.0 || true;

iotkit-admin observation wake 0;
