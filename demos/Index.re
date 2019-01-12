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