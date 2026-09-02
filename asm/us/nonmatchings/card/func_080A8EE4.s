.syntax unified
	.align 2, 0
	.global func_080A8EE4
	.thumb
	.thumb_func
	.type func_080A8EE4, %function
func_080A8EE4: @ 080A8EE4
	push {r4, r5, lr}
	add sp, #-0x008
	movs r2, #0xE1
	lsls r2, r2, #0x03
	adds r1, r0, r2
	movs r3, #0x00
	ldsh r5, [r1, r3]
	ldr r4, _080A8F1C @ =0x0000070A
	adds r1, r0, r4
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0xEC
	lsls r3, r3, #0x01
	adds r2, r0, r3
	ldr r3, [r0, #0x0C]
	movs r4, #0x14
	str r4, [sp, #0x000]
	ldr r4, _080A8F20 @ =0x0000070C
	adds r0, r0, r4
	ldrb r0, [r0, #0x00]
	str r0, [sp, #0x004]
	adds r0, r5, #0x0
	bl func_080664D8
	add sp, #0x008
	pop {r4, r5}
	pop {r0}
	bx r0
_080A8F1C: .4byte 0x0000070A
_080A8F20: .4byte 0x0000070C
.syntax divided
