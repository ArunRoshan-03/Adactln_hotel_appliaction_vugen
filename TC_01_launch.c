TC_01_launch()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");
	web_url("{base_url}", 
		"URL={scheme}//{base_url}/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/js/login.js", ENDITEM, 
		"Url=/css/main.css", ENDITEM, 
		"Url=/img/AdactIn_logo.png", ENDITEM, 
		"Url=/img/main-image-hotel-app.png", ENDITEM, 
		"Url=/img/google-play.png", ENDITEM, 
		"Url=/img/hotel.jpg", ENDITEM, 
		"Url=/img/ios-button.png", ENDITEM, 
		LAST);
	lr_think_time(think_time);
	return 0;
}
