.syntax unified
	.align 2, 0
	.global func_080D2C1C
	.thumb
	.thumb_func
	.type func_080D2C1C, %function
func_080D2C1C: @ 080D2C1C
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x15
	movs r2, #0xF8
	lsls r2, r2, #0x0D
	ands r2, r0
	lsrs r2, r2, #0x10
	ldr r0, _080D2C40 @ =0x0203C470
	lsls r3, r3, #0x02
	adds r0, #0x2C
	adds r3, r3, r0
	movs r1, #0x01
	lsls r1, r2
	ldr r0, [r3, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _080D2C44
	movs r0, #0x00
	b _080D2C46
_080D2C40: .4byte 0x0203C470
_080D2C44:
	movs r0, #0x01
_080D2C46:
	bx lr
.syntax divided
