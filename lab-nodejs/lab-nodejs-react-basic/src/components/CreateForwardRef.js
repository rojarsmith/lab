import React from "react";

// When should I use React Ref API?
// Manage focus events, text areas (text section), multimedia playback behavior (media playback)
// Drive the necessary animation behavior
// Interaction between third-party libraries and DOM components
//
// Can not use with Functional Component.
class MyComponent extends React.Component {
    constructor(props) {
        super(props);

        this.inputRef = React.createRef();
        this.inputRef2 = React.createRef();
    }

    render() {
        return ( 
            <div>
                <input type="text" ref={this.inputRef} />
                <input type="text" ref={this.inputRef2} />
            </div>
        );
    }

    componentDidMount() {
        this.inputRef.current.focus();
        this.inputRef2.current.focus();
    }
}

export { MyComponent };

// const FancyButton = React.forwardRef((props, ref) => (
//     <button ref={}>

//     </button>
// ));

// export default function CreateForwardRef(props) {

// }