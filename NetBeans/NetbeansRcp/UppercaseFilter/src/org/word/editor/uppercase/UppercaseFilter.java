/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package org.word.editor.uppercase;

import org.openide.util.lookup.ServiceProvider;
import org.word.editor.api.WordFilter;

/**
 *
 * @author Rojar.Wu
 */
@ServiceProvider(service=WordFilter.class)
public class UppercaseFilter implements WordFilter {
    
    @Override
    public String process(String s){
        return  s.toUpperCase();
    }
}
