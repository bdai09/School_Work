package com.example.a3;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.TextView;

import java.util.List;

public class MainActivity extends AppCompatActivity {
	ListView list;
	TextView buttonAdd, buttonExit;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
//		linearLayout = findViewById(R.id.layoutListViewID);
		DatabaseHandler databaseHandler1 = new DatabaseHandler(getApplicationContext());
		final List<String> listItems0 = databaseHandler1.getAllItems0();
		final String[] listItems0a = listItems0.toArray(new String[0]);
		final List<String> listItems1 = databaseHandler1.getAllItems1();
		final String[] listItems1a = listItems1.toArray(new String[0]);
		final List<String> listItems2 = databaseHandler1.getAllItems2();
		final String[] listItems2a = listItems2.toArray(new String[0]);
		final List<String> listItems3 = databaseHandler1.getAllItems3();
		final String[] listItems3a = listItems3.toArray(new String[0]);
		final List<String> listItems4 = databaseHandler1.getAllItems4();
		final String[] listItems4a = listItems4.toArray(new String[0]);

		final CustomListAdapter adapter = new CustomListAdapter(this, listItems0a,
						listItems1a, listItems2a, listItems3a, listItems4a);
		list = findViewById(R.id.androidlist);
		list.setAdapter(adapter);
		list.setOnItemClickListener(new AdapterView.OnItemClickListener() {
			@Override
			public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
				Intent intent = new Intent(MainActivity.this, DetailsActivity.class);
				intent.putExtra("itemname0", listItems0a[position]);
				intent.putExtra("itemname1", listItems1a[position]);
				intent.putExtra("itemname2", listItems2a[position]);
				intent.putExtra("itemname3", listItems3a[position]);
				intent.putExtra("itemname4", listItems4a[position]);
				intent.putExtra("command", "ud");
				startActivity(intent);
			}
		});

		buttonExit = findViewById(R.id.button_exit);
		buttonExit.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View view) {
				finishAffinity();
			}
		});

		buttonAdd = findViewById(R.id.button_add_team);
		buttonAdd.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				Intent intent = new Intent(MainActivity.this, DetailsActivity.class);
				intent.putExtra("itemname0", "");
				intent.putExtra("itemname1", "");
				intent.putExtra("itemname2", "");
				intent.putExtra("itemname3", "");
				intent.putExtra("itemname4", "");
				intent.putExtra("command", "add");
				startActivity(intent);
			}
		});
	}
}