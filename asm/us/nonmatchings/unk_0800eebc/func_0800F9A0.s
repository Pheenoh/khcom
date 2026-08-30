.syntax unified
	.align 2, 0
	.global func_0800F9A0
	.thumb
	.thumb_func
	.type func_0800F9A0, %function
func_0800F9A0: @ 0800F9A0
	push {lr}
	ldr r3, _0800FA18 @ =0x02039CA8
	movs r2, #0x00
	movs r0, #0x50
	strh r0, [r3, #0x00]
	adds r0, #0xC3
	strh r0, [r3, #0x02]
	movs r0, #0x08
	strh r0, [r3, #0x04]
	movs r0, #0x0A
	strh r0, [r3, #0x06]
	str r2, [r3, #0x08]
	movs r0, #0x01
	strb r0, [r3, #0x10]
	movs r0, #0x00
	movs r1, #0x00
	str r0, [r3, #0x14]
	str r1, [r3, #0x18]
	str r0, [r3, #0x1C]
	str r1, [r3, #0x20]
	str r0, [r3, #0x24]
	str r1, [r3, #0x28]
	str r0, [r3, #0x2C]
	str r1, [r3, #0x30]
	str r0, [r3, #0x34]
	str r1, [r3, #0x38]
	str r0, [r3, #0x3C]
	str r1, [r3, #0x40]
	str r0, [r3, #0x44]
	str r1, [r3, #0x48]
	str r0, [r3, #0x4C]
	str r1, [r3, #0x50]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	str r0, [r3, #0x5C]
	str r1, [r3, #0x60]
	str r0, [r3, #0x64]
	str r1, [r3, #0x68]
	str r0, [r3, #0x6C]
	str r1, [r3, #0x70]
	str r0, [r3, #0x74]
	str r1, [r3, #0x78]
	str r2, [r3, #0x7C]
	adds r0, r3, #0x0
	adds r0, #0x80
	strh r2, [r0, #0x00]
	adds r0, #0x02
	strh r2, [r0, #0x00]
	adds r0, #0x02
	strh r2, [r0, #0x00]
	movs r0, #0x19
	str r0, [r3, #0x0C]
	bl func_080C6FF8
	bl func_080DDEA4
	bl func_08109620
	pop {r0}
	bx r0
_0800FA18: .4byte 0x02039CA8
.syntax divided
