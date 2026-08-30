.syntax unified
	.align 2, 0
	.global func_08005550
	.thumb
	.thumb_func
	.type func_08005550, %function
func_08005550: @ 08005550
	cmp r0, #0x01
	beq _0800556C
	cmp r0, #0x01
	bcc _08005564
	cmp r0, #0x02
	beq _08005574
	cmp r0, #0x03
	beq _0800557C
	movs r0, #0x00
	b _08005584
_08005564:
	ldr r0, _08005568 @ =0x03007544
	b _0800557E
_08005568: .4byte 0x03007544
_0800556C:
	ldr r0, _08005570 @ =0x03007538
	b _0800557E
_08005570: .4byte 0x03007538
_08005574:
	ldr r0, _08005578 @ =0x03007520
	b _0800557E
_08005578: .4byte 0x03007520
_0800557C:
	ldr r0, _08005588 @ =0x0300755C
_0800557E:
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_08005584:
	bx lr
	.byte 0x00, 0x00
_08005588: .4byte 0x0300755C
.syntax divided
