package com.example.l7;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;


public class Main2Activity extends AppCompatActivity {
	String[] itemName;
	String[] itemDept;
	String[] itemYear;

	String[] itemName2;
	String[] itemDept2;
	String[] itemYear2;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main2);

		Intent intent=getIntent();
		itemName=intent.getStringArrayExtra("stringName");
		itemDept=intent.getStringArrayExtra("stringDept");
		itemYear=intent.getStringArrayExtra("stringYear");

		itemName2=intent.getStringArrayExtra("stringName2");
		itemDept2=intent.getStringArrayExtra("stringDept2");
		itemYear2=intent.getStringArrayExtra("stringYear2");


		CustomListAdapter adapterCarol = new CustomListAdapter(this, itemName);
		final ListView listViewBob = findViewById(R.id.listViewID);
		listViewBob.setAdapter(adapterCarol);

		listViewBob.setOnItemClickListener(new AdapterView.OnItemClickListener() {
			@Override
			public void onItemClick(AdapterView<?> parent, View view, int i, long id) {
				if(itemName[i]!=null) {
					Intent intent = new Intent(Main2Activity.this, DetailsActivity.class);
					intent.putExtra("itemName", itemName[i]);
					intent.putExtra("itemDept", itemDept[i]);
					intent.putExtra("itemYear", itemYear[i]);
					startActivity(intent);
				}
			}
		});

		CustomListAdapterTwo adapterCarol2 = new CustomListAdapterTwo(this, itemName2);
		ListView listViewBob2 = findViewById(R.id.listViewID2);
		listViewBob2.setAdapter(adapterCarol2);

		listViewBob2.setOnItemClickListener(new AdapterView.OnItemClickListener() {
			@Override
			public void onItemClick(AdapterView<?> parent, View view, int i, long id) {
				if(itemName2[i]!=null) {
					Intent intent = new Intent(Main2Activity.this, Details2Activity.class);
					intent.putExtra("itemName2", itemName2[i]);
					intent.putExtra("itemDept2", itemDept2[i]);
					intent.putExtra("itemYear2", itemYear2[i]);
					startActivity(intent);
				}
			}
		});
	}
}
class CustomListAdapter extends ArrayAdapter<String>{
	private Activity context;
	private String[] name;
	CustomListAdapter(Activity context, String[] name2){
		super(context,R.layout.individual_list_item,name2);
		this.context=context;
		this.name=name2;
	}
	public View getView(int position, View view, ViewGroup parent){
		LayoutInflater inflater=context.getLayoutInflater();
		View rowView=inflater.inflate(R.layout.individual_list_item,null,true);
		TextView tvName=rowView.findViewById(R.id.view1);
		tvName.setText(name[position]);
		return rowView;
	}
}

class CustomListAdapterTwo extends ArrayAdapter<String>{
	private Activity context;
	private String[] name;
	CustomListAdapterTwo(Activity context, String[] name2){
		super(context,R.layout.individual_list_item2,name2);
		this.context=context;
		this.name=name2;
	}
	public View getView(int position, View view, ViewGroup parent){
		LayoutInflater inflater=context.getLayoutInflater();
		View rowView=inflater.inflate(R.layout.individual_list_item2,null,true);
		TextView tvName=rowView.findViewById(R.id.view2);
		tvName.setText(name[position]);
		return rowView;
	}
}
