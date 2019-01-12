module D = Webapi.Dom;
module Doc = D.Document;
let appElement = Doc.getElementById("app", D.document);

open Jest;
open LitHtml;

let name = "Jane";
let write = () => {
  let hello = html([%bs.raw "html`blablah`"]);
  switch (appElement) {
  | Some(appElement) => render(hello, `element(appElement))
  | None => Js.log("no element to render on ")
  };
};

open Expect;

describe("LitHtml", () =>
  test("#html does not throw", () =>
    expect(() =>
      write()
    ) |> not |> toThrow
  )
);