.syntax unified
	.align 2, 0
	.global func_08060A2C
	.thumb
	.thumb_func
	.type func_08060A2C, %function
func_08060A2C: @ 08060A2C
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _08060A50
	adds r0, r1, #0x0
	bl func_080609AC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x05
	bl __udivsi3
	lsls r0, r0, #0x11
	b _08060A6A
_08060A50:
	ldr r0, _08060A70 @ =0x00000FFF
	ands r0, r1
	bl func_080609AC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x05
	bl __udivsi3
	lsls r0, r0, #0x11
	movs r1, #0xA0
	lsls r1, r1, #0x0C
	adds r0, r0, r1
_08060A6A:
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
_08060A70: .4byte 0x00000FFF
.syntax divided
