orders()
{

	lr_start_transaction("TC_07 View Order");

	web_add_auto_header("Accept", 
		"text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Accept-Encoding", 
		"gzip, deflate, br");

	web_add_header("Accept-Language", 
		"en-US,en;q=0.9");

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(35);

	web_url("6839", 
		"URL=https://jpetstore.cfapps.io/my/orders/6839", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/my/orders", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("TC_07 View Order",LR_AUTO);

	return 0;
}