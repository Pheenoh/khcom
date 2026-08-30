.syntax unified
	.align 2, 0
	.global func_08034668
	.thumb
	.thumb_func
	.type func_08034668, %function
func_08034668: @ 08034668
	push {r4, r5, lr}
	add sp, #-0x010
	mov r2, sp
	adds r1, r0, #0x0
	ldm r1!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldr r1, [r1, #0x00]
	str r1, [r2, #0x00]
	ldr r3, _080346B0 @ =0x08121400
	ldrb r1, [r0, #0x14]
	lsls r1, r1, #0x01
	adds r1, r1, r3
	movs r4, #0x00
	ldsh r2, [r1, r4]
	lsls r2, r2, #0x03
	ldr r1, [sp, #0x000]
	adds r1, r1, r2
	str r1, [sp, #0x000]
	ldrb r0, [r0, #0x14]
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r5, #0x00
	ldsh r1, [r0, r5]
	lsls r1, r1, #0x03
	ldr r0, [sp, #0x004]
	subs r0, r0, r1
	str r0, [sp, #0x004]
	mov r0, sp
	bl func_080DFCDC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080346B4
	movs r0, #0x00
	b _080346B6
_080346B0: .4byte 0x08121400
_080346B4:
	movs r0, #0x01
_080346B6:
	add sp, #0x010
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
