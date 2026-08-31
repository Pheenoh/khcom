.syntax unified
	.align 2, 0
	.global func_080C5DC0
	.thumb
	.thumb_func
	.type func_080C5DC0, %function
func_080C5DC0: @ 080C5DC0
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	ldr r1, _080C5E34 @ =0x0203C38C
	movs r0, #0x00
	strb r0, [r1, #0x00]
	ldr r0, _080C5E38 @ =0x020397F0
	movs r1, #0x00
	str r1, [r0, #0x00]
	ldr r0, _080C5E3C @ =0x02039B60
	strb r1, [r0, #0x00]
	ldr r0, _080C5E40 @ =0x02039804
	mov r9, r0
	ldr r7, _080C5E44 @ =0x020397F8
	ldr r1, _080C5E48 @ =0x0203C3B4
	mov r12, r1
	ldr r0, _080C5E4C @ =0x0203C388
	mov r8, r0
	ldr r1, _080C5E50 @ =0x02039B68
	movs r2, #0x00
	adds r0, r1, #0x6
_080C5DF0:
	strh r2, [r0, #0x00]
	subs r0, #0x02
	cmp r0, r1
	bge _080C5DF0
	movs r1, #0x00
	ldr r4, _080C5E54 @ =0x020397E0
	movs r3, #0x00
_080C5DFE:
	lsls r0, r1, #0x01
	adds r2, r1, #0x1
	movs r1, #0x03
	adds r0, r0, r4
	adds r0, #0x0C
_080C5E08:
	strh r3, [r0, #0x00]
	subs r0, #0x04
	subs r1, #0x01
	cmp r1, #0x00
	bge _080C5E08
	adds r1, r2, #0x0
	cmp r1, #0x01
	ble _080C5DFE
	movs r0, #0x00
	mov r1, r9
	str r5, [r1, #0x00]
	str r6, [r7, #0x00]
	mov r1, r12
	strh r0, [r1, #0x00]
	mov r1, r8
	strh r0, [r1, #0x00]
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080C5E34: .4byte 0x0203C38C
_080C5E38: .4byte 0x020397F0
_080C5E3C: .4byte 0x02039B60
_080C5E40: .4byte 0x02039804
_080C5E44: .4byte 0x020397F8
_080C5E48: .4byte 0x0203C3B4
_080C5E4C: .4byte 0x0203C388
_080C5E50: .4byte 0x02039B68
_080C5E54: .4byte 0x020397E0
.syntax divided
