const std = @import("std");

// from: https://ziglang.org/documentation/master/#Hello-World
// zig build-exe hello.zig
// ./hello 


pub fn main() !void {
    const stdout = std.io.getStdOut().writer();
    try stdout.print("Hello, {s}!\n", .{"world"});
}
