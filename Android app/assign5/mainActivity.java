package com.example.myapplication;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    TextView url;
    ListView linearLayoutListView;
    String stringURL =
            "https://earthquake.usgs.gov/fdsnws/event/1/query?format=geojson&starttime=2012-01-01&minmagnitude=6&limit=20&orderby=time";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        QuakeAsyncTask task = new QuakeAsyncTask();
        task.execute(stringURL);
    }

    class QuakeAsyncTask extends AsyncTask<String, Void, List<String>> {

        @Override
        protected List<String> doInBackground(String... stringurl) {
            return Utils.fetchEarthquakeData(stringurl[0]);
        }

        public void onPostExecute(List<String> postExecuteResult) {


            final CustomListAdapter arrayAdapter = new CustomListAdapter(MainActivity.this, postExecuteResult);
            linearLayoutListView = findViewById(R.id.listViewManyItemsID);
            linearLayoutListView.setAdapter(arrayAdapter);


            linearLayoutListView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
                public void onItemClick(AdapterView<?> parent, View view, int position, long id) {

                    String url = ((TextView) view.findViewById(R.id.url)).getText().toString();
                    /*This data is coming from an invisible text box from the one_quake
                    if i dont put this line then it will extract the text box of the first position only.
                     */


//                    url = findViewById(R.id.url);
//                    String s = url.getText().toString();

                        Intent browserIntent = new Intent(Intent.ACTION_VIEW, Uri.parse(url));
                       startActivity(browserIntent);


                }
            });


        }
    }
}
