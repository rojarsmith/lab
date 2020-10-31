// function withTodosNull(Component) {
//   return function (props) {
//     return !props.todos
//       ? null
//       : <Component {...props} />
//   }
// }

// JavaScript ES6 arrow functions
export const withTodosNull = (Component) => (props) =>
  !props.todos
    ? null
    : <Component {...props} />

    export const withCondition = (conditionalRenderingFn) => (Component) => (props) =>
  conditionalRenderingFn(props)
    ? null
    : <Component {...props} />

    export const withEither = (conditionalRenderingFn, EitherComponent) => (Component) => (props) =>
  conditionalRenderingFn(props)
    ? <EitherComponent />
    : <Component {...props} />

    export const withTodosEmpty = (Component) => (props) =>
  !props.todos.length
    ? <div><p>You have no Todos.</p></div>
    : <Component {...props} />

// JavaScript ES6 rest destructuring 
export const withLoadingIndicator = (Component) => ({ isLoadingTodos, ...others }) =>
  isLoadingTodos
    ? <div><p>Loading todos ...</p></div>
    : <Component {...others} />

// module.exports = {
//   withTodosNull: withTodosNull,
//   withCondition: withCondition,
//   withEither: withEither,
//   withTodosEmpty: withTodosEmpty,
//   withLoadingIndicator: withLoadingIndicator
// };
