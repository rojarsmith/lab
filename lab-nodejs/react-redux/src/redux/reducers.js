import { INCREMENT, DECREMENT } from './actions';

export function counter(
    state = { number: 0, name: 'Rojar'},
    action) {
        console.log('counter', state, action);
        switch (action.type) {
            case INCREMENT:
                state.number = state.number + action.data;
                return state;
            case DECREMENT:
                state.number = state.number - action.data;
                return state;
            default: return state;
        }
}
