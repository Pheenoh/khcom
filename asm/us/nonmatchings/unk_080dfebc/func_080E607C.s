.syntax unified
	.align 2, 0
	.global func_080E607C
	.thumb
	.thumb_func
	.type func_080E607C, %function
func_080E607C: @ 080E607C
	push {r4, r5, r6, r7, lr}
	add sp, #-0x020
	ldr r0, _080E6088 @ =0x02039C98
	bl func_08000C8C
	b _080E60C0
_080E6088: .4byte 0x02039C98
_080E608C:
	ldr r2, [r4, #0x30]
	str r2, [sp, #0x000]
	ldr r0, [r4, #0x34]
	str r0, [sp, #0x004]
	add r1, sp, #0x008
	adds r0, r4, #0x0
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	mov r1, sp
	ldrb r0, [r4, #0x10]
	strb r0, [r1, #0x18]
	ldr r0, [r4, #0x14]
	str r0, [sp, #0x01C]
	ldr r0, _080E60F8 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	adds r0, #0xB4
	ldr r1, [r2, #0x10]
	mov r2, sp
	bl func_08000E14
	adds r0, r4, #0x0
	adds r0, #0x1C
	bl func_08000CD4
_080E60C0:
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _080E608C
	ldr r4, _080E60FC @ =0x02039C98
	adds r0, r4, #0x0
	bl func_08000BA4
	adds r7, r4, #0x0
	subs r7, #0x8C
	adds r5, r4, #0x0
	subs r5, #0xA8
	adds r4, r7, #0x0
	movs r6, #0x02
_080E60DA:
	adds r0, r4, #0x0
	adds r1, r7, #0x0
	adds r1, #0x8C
	adds r2, r5, #0x0
	bl func_08000BB0
	adds r5, #0x38
	adds r4, #0x38
	subs r6, #0x01
	cmp r6, #0x00
	bge _080E60DA
	add sp, #0x020
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080E60F8: .4byte 0x02039BA0
_080E60FC: .4byte 0x02039C98
.syntax divided
