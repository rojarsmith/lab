import React from "react";
import classNames from "classnames";
import { makeStyles } from "@material-ui/core/styles";
import styles from '../jss/componentAStyle'

const useStyles = makeStyles(styles);

export default function ComponentA(props) {
    const { theme, className } = props;
    const classes = useStyles();
    const themeType =
        theme === "transparent" || theme == undefined ? false : true;
    const ComponentAClasses = classNames({
        [classes[theme]]: themeType,
    });
    const aClasses = classNames({
        [classes.a]: true
    });

    return (
        <div></div>
    );
}