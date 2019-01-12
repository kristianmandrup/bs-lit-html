# bs-lit-html

Bucklescript bindings for [lit-html](https://lit-html.polymer-project.org/)

## What is lit-html?

`lit-html` is a mini library for generating and updating HTML content. From a user perspective, lit-html feels a whole lot like [JSX](https://reactjs.org/docs/introducing-jsx.html), but it's all standard JavaScript and no compile step is required!

`lit-HTML` heavily optimise the updates just recalculate what effectively should be re-rendered instead of re-rendering the entire node, this behaviour is highlighted in the first h1 tag of our example: Preact is re-rendering the entire node including the text that is static by design (“Preact” word was static, the number instead is a random one I used for causing a DOM update), instead lit-HTML splits the string in what is static and what is not so it can update ONLY what potentially could change without the need of re-rendering anything else.

If you are wondering what is the black magic behind lit-HTML, I can summarise it in this way: _JUST WEB STANDARDS!_

[lit-html announcement video](https://www.youtube.com/watch?v=Io6JjgckHbg)

Also see [W3C Template instantion](https://w3c.github.io/webcomponents/proposals/Template-Instantiation)

## Rendering

lit-html uses "tagged string template literals" from ES2015, and you define your markup using the html`` tag.

lit-html is very JSX like but uses regular JavaScript

The cool thing about string template literals is that, for the same tagged template string, they return the same strings and only the values will differ:

This allows lit-html to return a `TemplateResult` object, which can be rendered to the DOM. `TemplateResult` has methods that can generate a <template> element which replaces the "holes" with `{{}}`, which allows storing the insertion points in the resulting DOM.

The interesting part here is that this is very compatible with the `Template Instantiation` proposal from Apple, which Google is a supporter of. Actually they are creating a so-called "prollyfill" for it and making a few changes from their experience with building and using `lit-html`.

Rendering is also quite simple, you just call `render()` giving it a `TemplateResult` and a container, such as `document.body` or any document `fragment`.

When you render, `lit-html` creates a `<template>` element using `TemplateResult`, and depending on where the insertion point is, different kinds of Pars are created, such as `AttributePart`, `NodePart` and even `TemplatePart`, which are then all stored in a `Template` object.

This is then rendered to the DOM, which means DOM is created from the `<template>` and values are added in the insertion points.

```js
let something = "sauce";
render(html(`This is awesome <span>${something}</span>`), document.body);
```

## Examples

See [lit-html-examples](https://github.com/LarsDenBakker/lit-html-examples) repo

## Usage

`$ yarn add bs-lit-html`

Add `bs-lit-html` as a dependency to `bs-dependencies` in `bsconfig.json`

Currently only includes a binding to the `html` and `render` function for rendering DOM using a `<template>` element.

```reason
open LitHtml;
module D = Webapi.Dom;
module Doc = D.Document;
let appElement = Doc.getElementById("app", D.document);

exception NoSuchElement;

let write = () => {
  let hello = html([%bs.raw "html`blablah`"]);
  switch (appElement) {
  | Some(appElement) => render(hello, `element(appElement))
  | None => raise(NoSuchElement)
  };
};
```

## State management

### Meosis state management using streams

- [Meosis](https://meiosis.js.org/)
- [Meosis using lit-html](https://meiosis.js.org/tutorial/10-using-lit-html.html)
- [Awesome State management](https://www.youtube.com/watch?v=KJSM2uFDzDY)

### Atama proxy state management

- [Atama](https://github.com/franciscop/atama#getting-started) state management using Proxy

## Running meosis lit demo

In your Chrome browser
enable [Experimental Web Platform features](chrome://flags/#enable-experimental-web-platform-features)

Install a http server such as [serve](https://www.npmjs.com/package/serve) or similar

Go to `meosis-lit` demo folder

```js
$ cd demos/meosis-lit
```

Serve the folder

```
$ serve .

Serving!                                      │
   │                                                 │
   │   - Local:            http://localhost:5000     │
   │   - On Your Network:  http://192.168.1.3:5000
```

Open the local endpoint such as `http://localhost:5000` in your browser

`$ open http://localhost:5000`

This should display the demo

## Resources

- [lit-html rendering explained](https://medium.com/@kennethrohde/a-bit-about-lit-html-rendering-2964c50ee56c)
- [A night experimenting with Lit-HTML](https://medium.com/@lucamezzalira/a-night-experimenting-with-lit-html-585a8c69892a)
- [Efficient Template Rendering Using lit-html](https://alligator.io/web-components/lit-html/)

# Build

```
npm run build
```

# Watch

```
npm run watch
```

# Editor

If you use `vscode`, Press `Windows + Shift + B` it will build automatically
