package com.example.a3;

import android.app.Activity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

public class CustomListAdapter extends ArrayAdapter<String> {
	Activity context;
	String[] itemname0;
	String[] itemname1;
	String[] itemname2;
	String[] itemname3;
	String[] itemname4;

	public CustomListAdapter(Activity contextPar, String[] itemname0Par, String[] itemname1Par,
													 String[] itemname2Par, String[] itemname3Par, String[] itemname4Par) {
		super(contextPar, R.layout.one_item, itemname0Par);
		context = contextPar;
		itemname0 = itemname0Par;
		itemname1 = itemname1Par;
		itemname2 = itemname2Par;
		itemname3 = itemname3Par;
		itemname4 = itemname4Par;
	}

	public View getView(int position, View view, ViewGroup parent) {
		LayoutInflater inflater = context.getLayoutInflater();
		View rowView = inflater.inflate(R.layout.one_item, null, true);
		TextView textCity = rowView.findViewById(R.id.text_city);
		TextView textName = rowView.findViewById(R.id.text_name);

		textCity.setText(itemname0[position]);
		textName.setText(itemname1[position]);
		return rowView;
	}
}
