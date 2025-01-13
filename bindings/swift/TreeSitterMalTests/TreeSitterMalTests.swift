import XCTest
import SwiftTreeSitter
import TreeSitterMal

final class TreeSitterMalTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_mal())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Mal grammar")
    }
}
