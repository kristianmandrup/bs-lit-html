open LitHtml;
module D = Webapi.Dom;
module Doc = D.Document;
let appElement = Doc.getElementById("app", D.document);

let name = "Jane";
let hello = html([%bs.raw {|<div>Hello $name</div>|}]);
render(hello, appElement);