module D = Webapi.Dom;
module Doc = D.Document;
let appElement = Doc.getElementById("app", D.document);

open Jest;
open LitHtml;

let name = "Jane";
let write = () => {
  let hello = html([%bs.raw {|<div>Hello $name</div>|}]);
  render(hello, appElement);
};

open Expect;

describe("LitHtml", () =>
  test("#html does not throw", () =>
    expect(() =>
      write()
    ) |> not |> toThrow
  )
);