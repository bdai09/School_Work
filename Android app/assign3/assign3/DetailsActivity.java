package com.example.a3;

import android.content.Intent;
import android.graphics.Color;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

public class DetailsActivity extends AppCompatActivity {
	EditText editText0, editText1, editText2, editText3, editText4;
	LinearLayout layoutTop, layoutBottom;
	TextView buttonAdd, buttonUpdate, buttonDelete, buttonExit;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_details);
		editText0 = findViewById(R.id.input_city);
		editText1 = findViewById(R.id.input_name);
		editText2 = findViewById(R.id.input_sport);
		editText3 = findViewById(R.id.input_MVP);
		editText4 = findViewById(R.id.input_stadium);

		buttonAdd = findViewById(R.id.button_add);
		buttonAdd.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				DatabaseHandler databaseHandler2 = new DatabaseHandler(getApplicationContext());
				String item0 = editText0.getText().toString();
				String item1 = editText1.getText().toString();
				String item2 = editText2.getText().toString();
				String item3 = editText3.getText().toString();
				String item4 = editText4.getText().toString();

				if (item0.length() != 0 && item1.length() != 0) {
					databaseHandler2.insertItem(item0, item1, item2, item3, item4);
					editText0.setText("");
					editText1.setText("");
					editText2.setText("");
					editText3.setText("");
					editText4.setText("");
				} else {
					Toast.makeText(getApplicationContext(), "City and Name " +
									"are required", Toast.LENGTH_SHORT).show();
				}
			}
		});

		buttonUpdate = findViewById(R.id.button_update);
		buttonUpdate.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
			}
		});

		buttonDelete = findViewById(R.id.button_delete);
		buttonDelete.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
			}
		});

		buttonExit = findViewById(R.id.button_exit);
		buttonExit.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				Intent intent = new Intent(DetailsActivity.this, MainActivity.class);
				startActivity(intent);
			}
		});

		Intent intent = getIntent();
		String stringData = intent.getStringExtra("itemname0");
		editText0.setText(stringData);
		stringData = intent.getStringExtra("itemname1");
		editText1.setText(stringData);
		stringData = intent.getStringExtra("itemname2");
		editText2.setText(stringData);
		stringData = intent.getStringExtra("itemname3");
		editText3.setText(stringData);
		stringData = intent.getStringExtra("itemname4");
		editText4.setText(stringData);
		stringData = intent.getStringExtra("command");
		layoutTop = findViewById(R.id.layoutTop);
		layoutBottom = findViewById(R.id.layoutBottom);

		if (stringData.equals("add")) {
			buttonDelete.setVisibility(View.GONE);
			buttonUpdate.setVisibility(View.GONE);
			buttonAdd.setVisibility(View.VISIBLE);
			layoutTop.setBackgroundColor(Color.parseColor("#FFBB33"));
			layoutBottom.setBackgroundColor(Color.parseColor("#AA66CC"));
		}

		if (stringData.equals("ud")) {
			buttonDelete.setAlpha(0.1f);
			buttonDelete.setVisibility(View.VISIBLE);
			buttonUpdate.setAlpha(0.1f);
			buttonUpdate.setVisibility(View.VISIBLE);
			buttonAdd.setVisibility(View.GONE);
			layoutTop.setBackgroundColor(Color.parseColor("#FF4444"));
			layoutBottom.setBackgroundColor(Color.parseColor("#AA66CC"));
		}
	}
}
