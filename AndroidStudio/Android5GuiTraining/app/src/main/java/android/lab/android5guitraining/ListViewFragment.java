package android.lab.android5guitraining;


import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.List;

/**
 * A simple {@link Fragment} subclass.
 */
public class ListViewFragment extends Fragment {

    private PeopleArrayAdapter peopleArrayAdapter;
    private ListView peopleListView; // displays weather info

//    public ListViewFragment() {
//        // Required empty public constructor
//    }


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View view = inflater.inflate(R.layout.fragment_list_view, container, false);
        peopleListView = (ListView)view.findViewById(R.id.peopleListView);

        return view;
    }

    @Override
    public void onStart() {
        super.onStart();

        List<People> peopleList = new ArrayList<>();



        peopleArrayAdapter = new PeopleArrayAdapter(this.getActivity(), peopleList);
        peopleListView.setAdapter(peopleArrayAdapter);

        peopleList.add(new People("AAA",1,2,3));
        peopleList.add(new People("BBB",4,5,6));
        peopleList.add(new People("AAA",1,2,3));
        peopleList.add(new People("BBB",4,5,6));
        peopleList.add(new People("AAA",1,2,3));
        peopleList.add(new People("BBB",4,5,6));
        peopleList.add(new People("AAA",1,2,3));
        peopleList.add(new People("BBB",4,5,6));
        peopleList.add(new People("AAA",1,2,3));
        peopleList.add(new People("BBB",4,5,6));
        peopleList.add(new People("AAA",1,2,3));
        peopleList.add(new People("BBB",4,5,6));
        peopleList.add(new People("AAA",1,2,3));
        peopleList.add(new People("BBB",4,5,6));
        peopleList.add(new People("AAA",1,2,3));
        peopleList.add(new People("BBB",4,5,6));
        peopleList.add(new People("AAA",1,2,3));
        peopleList.add(new People("BBB",4,5,6));
        peopleList.add(new People("AAA",1,2,3));
        peopleList.add(new People("BBB",4,5,6));
    }
}
