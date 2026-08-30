.syntax unified
	.align 2, 0
	.global func_080D2BF8
	.thumb
	.thumb_func
	.type func_080D2BF8, %function
func_080D2BF8: @ 080D2BF8
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x15
	movs r2, #0xF8
	lsls r2, r2, #0x0D
	ands r2, r0
	lsrs r2, r2, #0x10
	ldr r0, _080D2C18 @ =0x0203C470
	lsls r3, r3, #0x02
	adds r0, #0x2C
	adds r3, r3, r0
	movs r1, #0x01
	lsls r1, r2
	ldr r0, [r3, #0x00]
	orrs r0, r1
	str r0, [r3, #0x00]
	bx lr
_080D2C18: .4byte 0x0203C470
.syntax divided
