.syntax unified
	.align 2, 0
	.global func_080E8A24
	.thumb
	.thumb_func
	.type func_080E8A24, %function
func_080E8A24: @ 080E8A24
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0x0
	ldr r0, _080E8AC4 @ =0x0203C7AC
	ldr r2, [r0, #0x00]
	ldrb r1, [r6, #0x04]
	ldrh r0, [r2, #0x04]
	subs r0, r0, r1
	adds r0, #0x01
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	ldrb r1, [r6, #0x05]
	ldrh r0, [r2, #0x06]
	subs r0, r0, r1
	adds r0, #0x01
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r10, r0
	movs r1, #0x00
	cmp r1, r10
	bge _080E8AB6
_080E8A56:
	movs r4, #0x00
	lsls r1, r1, #0x10
	mov r8, r1
	cmp r4, r9
	bge _080E8AA8
	asrs r7, r1, #0x10
_080E8A62:
	lsls r4, r4, #0x10
	asrs r5, r4, #0x10
	ldr r2, [r6, #0x00]
	adds r0, r5, #0x0
	adds r1, r7, #0x0
	bl func_080E89E4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080E8A9A
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x64
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r6, #0x06]
	cmp r0, r1
	bcs _080E8A9A
	ldr r2, [r6, #0x08]
	ldr r3, [r6, #0x0C]
	adds r0, r5, #0x0
	adds r1, r7, #0x0
	bl func_080E893C
_080E8A9A:
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r4, r1
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r9
	blt _080E8A62
_080E8AA8:
	movs r0, #0x80
	lsls r0, r0, #0x09
	add r0, r8
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r10
	blt _080E8A56
_080E8AB6:
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080E8AC4: .4byte 0x0203C7AC
.syntax divided
