import { INCREMENT, DECREMENT, FIND_PERSON, FETCH_PERSON } from './actions';

export function counter(
    state = { number: 0, name: 'Rojar', id: 0},
    action) {
        console.log('counter', state, action);
        switch (action.type) {
            case INCREMENT:
                state.number = state.number + action.data;
                return state;
            case DECREMENT:
                state.number = state.number - action.data;
                return state;
            case FIND_PERSON:
                state.id = action.data;
                return state;
            case FETCH_PERSON:
                state.name = action.data;
                return state;
            default: return state;
        }
}
