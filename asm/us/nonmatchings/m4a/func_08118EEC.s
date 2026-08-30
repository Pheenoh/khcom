.syntax unified
	.align 2, 0
	.global func_08118EEC
	.thumb
	.thumb_func
	.type func_08118EEC, %function
func_08118EEC: @ 08118EEC
	push {r7, lr}
	add sp, #-0x008
	mov r7, sp
	str r0, [r7, #0x00]
	ldr r0, [r7, #0x00]
	str r0, [r7, #0x04]
	ldr r0, _08118F78 @ =0x0203C7D0
	ldr r1, [r7, #0x04]
	ldr r2, [r1, #0x00]
	ldr r1, [r0, #0x08]
	adds r0, r2, #0x0
	bl _call_via_r1
	ldr r0, _08118F78 @ =0x0203C7D0
	ldr r1, [r7, #0x04]
	ldr r2, [r1, #0x04]
	ldr r1, [r0, #0x08]
	adds r0, r2, #0x0
	bl _call_via_r1
	ldr r0, _08118F78 @ =0x0203C7D0
	ldr r1, [r7, #0x04]
	ldr r2, [r1, #0x08]
	ldr r1, [r0, #0x08]
	adds r0, r2, #0x0
	bl _call_via_r1
	ldr r0, _08118F78 @ =0x0203C7D0
	ldr r1, [r7, #0x04]
	ldr r2, [r1, #0x20]
	ldr r1, [r0, #0x0C]
	adds r0, r2, #0x0
	bl _call_via_r1
	ldr r0, _08118F78 @ =0x0203C7D0
	ldr r1, [r7, #0x04]
	ldr r2, [r1, #0x24]
	ldr r1, [r0, #0x0C]
	adds r0, r2, #0x0
	bl _call_via_r1
	ldr r0, [r7, #0x04]
	ldr r1, [r0, #0x40]
	cmp r1, #0x00
	beq _08118F54
	ldr r0, _08118F78 @ =0x0203C7D0
	ldr r1, [r7, #0x04]
	ldr r2, [r1, #0x28]
	ldr r1, [r0, #0x0C]
	adds r0, r2, #0x0
	bl _call_via_r1
_08118F54:
	ldr r0, _08118F78 @ =0x0203C7D0
	ldr r1, [r7, #0x04]
	ldr r2, [r1, #0x5C]
	ldr r1, [r0, #0x08]
	adds r0, r2, #0x0
	bl _call_via_r1
	ldr r0, _08118F78 @ =0x0203C7D0
	ldr r1, [r7, #0x04]
	ldr r2, [r0, #0x08]
	adds r0, r1, #0x0
	bl _call_via_r2
	add sp, #0x008
	pop {r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08118F78: .4byte 0x0203C7D0
.syntax divided
