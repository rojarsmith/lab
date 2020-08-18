import React from "react";
import classNames from "classnames";
import { makeStyles } from "@material-ui/core/styles";
import styles from '../jss/componentAStyle'

const useStyles = makeStyles(styles);

export default function ComponentA(props) {
    const { theme, className } = props;
    const classes = useStyles();
    const themeType =
        theme === "transparent" || theme === undefined ? false : true;
    const ComponentAClasses = classNames({
        [classes[theme]]: themeType,
        [className]: className !== undefined
    });
    const aClasses = classNames({
        [classes.a]: true
    });

    return (
        <div>
            <div className={ComponentAClasses}>
                <div>
                    <a href="http://localhost:3002/" >C1 Link</a>
                </div>
            </div>
            <div className={aClasses}>
                <div >
                    <a href="http://localhost:3002/" >C2 Link</a>
                </div>
            </div>
        </div>
    );
}