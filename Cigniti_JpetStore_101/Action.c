Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Accept", 
		"text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Accept-Encoding", 
		"gzip, deflate, br");

	web_add_auto_header("Accept-Language", 
		"en-US,en;q=0.9");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("catalog", 
		"URL=https://jpetstore.cfapps.io/catalog", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("TC_01 Launch");

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Cache-Control", 
		"max-age=0");

	web_image("logo-topbar.gif", 
		"Src=/images/logo-topbar.gif", 
		"Snapshot=t2.inf", 
		LAST);

	lr_end_transaction("TC_01 Launch",LR_AUTO);

	lr_start_transaction("TC_Login");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(12);

	web_link("Sign In", 
		"Text=Sign In", 
		"Snapshot=t4.inf", 
		LAST);

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Cache-Control", 
		"max-age=0");

	web_add_header("Origin", 
		"https://jpetstore.cfapps.io");

	web_submit_form("login", 
		"Snapshot=t5.inf", 
		ITEMDATA, 
		"Name=username", "Value={username}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		LAST);

	lr_end_transaction("TC_Login",LR_AUTO);

	lr_start_transaction("TC_03 My Account");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(16);

	web_link("My Account", 
		"Text=My Account", 
		"Snapshot=t6.inf", 
		LAST);

	lr_end_transaction("TC_03 My Account",LR_AUTO);

	lr_start_transaction("TC_04 My Order");

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	lr_think_time(19);

	web_link("My Orders", 
		"Text=My Orders", 
		"Snapshot=t7.inf", 
		LAST);

	lr_end_transaction("TC_04 My Order",LR_AUTO);

	lr_start_transaction("TC_05 Logout");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_link("Sign Out", 
		"Text=Sign Out", 
		"Snapshot=t8.inf", 
		LAST);

	lr_end_transaction("TC_05 Logout",LR_AUTO);

	return 0;
}
