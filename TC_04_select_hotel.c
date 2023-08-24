TC_04_select_hotel()
{
	web_reg_save_param_ex(
		"ParamName=C_gst_price",
		"LB/IC=<input name=\"gst_dis\" type=\"text\" class=\"disable_text\" id=\"gst_dis\" value=\"",
		"RB/IC=\" disabled=\"disabled\" />",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/BookHotel.php*",
		LAST);

	web_reg_save_param_ex(
		"ParamName=C_final_price",
		"LB/IC=<input type=\"text\" name=\"final_price_dis\" id=\"final_price_dis\" class=\"disable_text\" value=\"",
		"RB/IC=\" disabled=\"disabled\" />",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/BookHotel.php*",
		LAST);


	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Book A Hotel ",
		LAST);

	web_submit_data("BookHotel.php",
		"Action={scheme}//{base_url}/BookHotel.php",
		"Method=POST",
		"RecContentType=text/html",
		"Referer={scheme}//{base_url}/SelectHotel.php",
		"Snapshot=t43.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=radiobutton_0", "Value=0", ENDITEM,
		"Name=total_radiobutton", "Value=1", ENDITEM,
		"Name=hotel_name_0", "Value={p_hotels}", ENDITEM,
		"Name=location_0", "Value={p_locations}", ENDITEM,
		"Name=rooms_0", "Value={p_rooms} Rooms", ENDITEM,
		"Name=arr_date_0", "Value={p_pick_in}", ENDITEM,
		"Name=dep_date_0", "Value={p_pick_out}", ENDITEM,
		"Name=no_days_0", "Value={P_total_days} Days", ENDITEM,
		"Name=room_type_0", "Value={p_room_types}", ENDITEM,
		"Name=price_night_0", "Value={P_price_night}", ENDITEM,
		"Name=total_price_0", "Value={p_total_price}", ENDITEM,
		"Name=continue", "Value=Continue", ENDITEM,
		"Name=hotel_name", "Value={p_hotels}", ENDITEM,
		"Name=location_name", "Value={p_locations}", ENDITEM,
		"Name=room_types", "Value={p_room_types}", ENDITEM,
		"Name=rooms_no", "Value={p_rooms}", ENDITEM,
		"Name=arr_date", "Value={p_pick_in}", ENDITEM,
		"Name=dep_date", "Value={p_pick_out}", ENDITEM,
		"Name=no_days", "Value={P_total_days}", ENDITEM,
		"Name=adults_room", "Value={p_adults_rooms}", ENDITEM,
		"Name=children_room", "Value={p_children_rooms}", ENDITEM,
		"Name=price_night", "Value={P_price_night}", ENDITEM,
		"Name=total_price", "Value={p_total_price}", ENDITEM,
		LAST);
		lr_param_sprintf("p_gst_prices", "%s", lr_eval_string("{C_gst_price}"));
		lr_param_sprintf("p_final_price", "%s", lr_eval_string("{C_final_price}"));
		
		lr_think_time(think_time);
	return 0;
}

