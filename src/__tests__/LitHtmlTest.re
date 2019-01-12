module D = Webapi.Dom;
module Doc = D.Document;
let appElement = Doc.getElementById("app", D.document);

open Jest;
open LitHtml;

exception NoSuchElement;

let name = "Jane";
let write = () => {
  let hello = html([%bs.raw "html`blablah`"]);
  switch (appElement) {
  | Some(appElement) => render(hello, `element(appElement))
  | None => raise(NoSuchElement)
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