.syntax unified
	.align 2, 0
	.global func_080E92B8
	.thumb
	.thumb_func
	.type func_080E92B8, %function
func_080E92B8: @ 080E92B8
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r5, _080E92F0 @ =0x02039BB0
	ldrb r0, [r5, #0x0C]
	strb r0, [r4, #0x00]
	ldrb r0, [r5, #0x0E]
	strb r0, [r4, #0x01]
	ldr r1, _080E92F4 @ =0x0203C590
	adds r0, r4, #0x4
	movs r2, #0x87
	lsls r2, r2, #0x02
	bl _0811F030
	movs r0, #0xC2
	lsls r0, r0, #0x01
	adds r5, r5, r0
	adds r0, #0x9C
	adds r4, r4, r0
	movs r1, #0x0C
_080E92DE:
	ldm r5!, {r0}
	stm r4!, {r0}
	subs r1, #0x01
	cmp r1, #0x00
	bge _080E92DE
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080E92F0: .4byte 0x02039BB0
_080E92F4: .4byte 0x0203C590
.syntax divided
