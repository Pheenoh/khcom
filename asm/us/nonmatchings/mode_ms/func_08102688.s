.syntax unified
	.align 2, 0
	.global func_08102688
	.thumb
	.thumb_func
	.type func_08102688, %function
func_08102688: @ 08102688
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsrs r0, r0, #0x0C
	lsrs r1, r1, #0x0E
	adds r0, r0, r1
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	ldr r0, _081026BC @ =0x000001FF
	cmp r1, r0
	bhi _081026B8
	ldr r0, _081026C0 @ =0x02035B68
	lsrs r2, r2, #0x14
	lsls r2, r2, #0x01
	adds r2, r2, r0
	movs r0, #0x0F
	ands r0, r1
	movs r1, #0x01
	lsls r1, r0
	ldrh r0, [r2, #0x00]
	bics r0, r1
	strh r0, [r2, #0x00]
_081026B8:
	bx lr
	.byte 0x00, 0x00
_081026BC: .4byte 0x000001FF
_081026C0: .4byte 0x02035B68
.syntax divided
