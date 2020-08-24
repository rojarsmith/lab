const grayColor = [
    "#999",
    "#3C4858",
    "#eee",
    "#343434",
    "#585858",
    "#232323",
    "#ddd",
    "#6c757d",
    "#333",
    "#212121",
    "#777",
    "#D2D2D2",
    "#AAA",
    "#495057",
    "#e5e5e5",
    "#555",
    "#f9f9f9",
    "#ccc",
    "#444",
    "#f2f2f2",
    "#89229b",
    "#c0c1c2",
    "#9a9a9a",
    "#f5f5f5",
    "#505050",
    "#1f1f1f"
];

const primaryColor = [
    "#9c27b0",
    "#ab47bc",
    "#8e24aa",
    "#af2cc5",
    "#e1bee7",
    "#ba68c8"
];

const whiteColor = "#FFF";

const componentAtyle = {
    dark: {
        background:
            "radial-gradient(ellipse at center," +
            grayColor[4] +
            " 0," +
            grayColor[5] +
            " 100%)",
        backgroundSize: "550% 450%",
        "& a": {
            color: whiteColor,
            opacity: ".86",
            "&:visited": {
                color: whiteColor
            },
            "&:focus, &:hover": {
                opacity: 1
            }
        },
    },
    white: {
        backgroundColor: whiteColor,
        color: grayColor[1],
        textDecoration: "none",
        "& a": {
            "&:visited": {
                color: grayColor[1]
            },
            "&:hover, &:focus": {
                color: grayColor[20]
            }
        }
    },
    a: {
        color: primaryColor[0],
        textDecoration: "none",
        backgroundColor: "transparent"
    }
}

export default componentAtyle;