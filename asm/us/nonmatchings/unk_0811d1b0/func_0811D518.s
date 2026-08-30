.syntax unified
	.align 2, 0
	.global func_0811D518
	.thumb
	.thumb_func
	.type func_0811D518, %function
func_0811D518: @ 0811D518
	ldr r2, _0811D534 @ =0x0203C7F0
	ldr r0, [r2, #0x44]
	cmp r0, #0x00
	beq _0811D548
	ldr r0, _0811D538 @ =0x04000102
	movs r1, #0x00
	strh r1, [r0, #0x00]
	movs r1, #0x00
	str r1, [r2, #0x44]
	ldr r0, [r2, #0x40]
	cmp r0, #0x01
	bne _0811D540
	ldr r0, _0811D53C @ =0x040000C4
	b _0811D546
_0811D534: .4byte 0x0203C7F0
_0811D538: .4byte 0x04000102
_0811D53C: .4byte 0x040000C4
_0811D540:
	ldr r0, _0811D54C @ =0x040000C4
	str r1, [r0, #0x00]
	adds r0, #0x0C
_0811D546:
	str r1, [r0, #0x00]
_0811D548:
	bx lr
	.byte 0x00, 0x00
_0811D54C: .4byte 0x040000C4
.syntax divided
