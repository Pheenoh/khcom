.syntax unified
	.align 2, 0
	.global func_080B1C70
	.thumb
	.thumb_func
	.type func_080B1C70, %function
func_080B1C70: @ 080B1C70
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	add sp, #-0x004
	adds r6, r0, #0x0
	adds r5, r1, #0x0
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	lsls r5, r5, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsrs r5, r5, #0x0C
	ldr r0, _080B1CC8 @ =0x09619444
	adds r5, r5, r0
	ldr r0, _080B1CCC @ =0x02034B4C
	mov r8, r0
	lsls r1, r6, #0x01
	adds r1, r1, r6
	lsls r1, r1, #0x03
	adds r1, #0x20
	ldr r0, [r0, #0x00]
	adds r0, r0, r1
	ldrb r1, [r5, #0x0C]
	ldr r3, [r5, #0x04]
	ldr r4, [r5, #0x00]
	str r4, [sp, #0x000]
	bl func_08005974
	mov r1, r8
	ldr r0, [r1, #0x00]
	lsls r6, r6, #0x02
	adds r0, #0x08
	adds r0, r0, r6
	ldr r0, [r0, #0x00]
	ldr r1, [r5, #0x08]
	bl func_08002A10
	add sp, #0x004
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B1CC8: .4byte 0x09619444
_080B1CCC: .4byte 0x02034B4C
.syntax divided
