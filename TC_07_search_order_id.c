TC_07_search_order_id()
{
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Search Order Id ",
		LAST);

	web_custom_request("BookedItinerary.php_2",
		"URL={scheme}//{base_url}/BookedItinerary.php",
		"Method=POST",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={scheme}//{base_url}/BookedItinerary.php",
		"Snapshot=t48.inf",
		"Mode=HTML",
		"Body=order_id_901969={C_order_id}&hotel_name_901969=Hotel+Cornice&location_901969={p_locations}&rooms_901969=7+Rooms&first_name_901969={p_username}&last_name_901969={p_lastname}&arr_date_901969={p_pick_in}&dep_date_901969={p_pick_out}&no_days_901969=3+Days&room_type_901969={p_room_types}&price_night_901969=AUD+%24+200&total_price_901969=AUD+%24+671",
		LAST);
	lr_think_time(think_time);
	return 0;
}

