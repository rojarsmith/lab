package android.lab.android5guitraining;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import java.util.List;

public class PeopleArrayAdapter extends ArrayAdapter<People> {
    private static class ViewHolder {
        TextView nameTextView;
        TextView ageTextView;
        TextView heightTextView;
        TextView weightTextView;
    }

    public PeopleArrayAdapter(Context context, List<People> resource) {
        super(context, -1, resource);
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        People people = getItem(position);

        ViewHolder viewHolder; // object that reference's list item's views
        if (convertView == null) {
            viewHolder = new ViewHolder();
            LayoutInflater inflater = LayoutInflater.from(getContext());
            convertView =
                    inflater.inflate(R.layout.list_item, parent, false);
            viewHolder.nameTextView = (TextView) convertView.findViewById(R.id.nameTextView);
            viewHolder.ageTextView =
                    (TextView) convertView.findViewById(R.id.ageTextView);
            viewHolder.heightTextView =
                    (TextView) convertView.findViewById(R.id.heightTextView);
            viewHolder.weightTextView =
                    (TextView) convertView.findViewById(R.id.weightTextView);
            convertView.setTag(viewHolder);
        }else
        {
            viewHolder = (ViewHolder) convertView.getTag();
        }


        //Context context = getContext();
        viewHolder.nameTextView.setText(people.name);
        viewHolder.ageTextView.setText(people.age.toString());
        viewHolder.heightTextView.setText(people.height.toString());
        viewHolder.weightTextView.setText(people.weight.toString());

            return convertView;
    }
}
