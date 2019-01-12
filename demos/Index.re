open LitHtml;
module D = Webapi.Dom;
module Doc = D.Document;
let appElement = Doc.getElementById("app", D.document);

let name = "Jane";
let hello = html({j|<div>Hello $name</div>|j}, ());
render(hello, appElement);