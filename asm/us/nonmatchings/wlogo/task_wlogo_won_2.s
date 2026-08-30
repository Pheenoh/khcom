.syntax unified
	.align 2, 0
	.global task_wlogo_won_2
	.thumb
	.thumb_func
	.type task_wlogo_won_2, %function
task_wlogo_won_2: @ 080B5198
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x018
	adds r6, r0, #0x0
	adds r0, #0xF2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _080B522C
	movs r0, #0x00
	mov r9, r0
	adds r1, r6, #0x0
	adds r1, #0x84
	str r1, [sp, #0x010]
	adds r2, r6, #0x0
	adds r2, #0x34
	str r2, [sp, #0x014]
	movs r3, #0x0C
	adds r3, r3, r6
	mov r10, r3
	adds r7, r6, #0x0
	adds r7, #0xCA
	movs r0, #0x09
	mov r8, r0
_080B51CC:
	ldrb r0, [r6, #0x0A]
	ldrh r1, [r7, #0x00]
	lsls r1, r1, #0x02
	ldr r2, _080B523C @ =0x09EF180C
	adds r1, r1, r2
	ldr r1, [r1, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x01
	movs r3, #0x00
	bl func_08002CB4
	adds r5, r0, #0x0
	mov r3, r10
	adds r3, #0x04
	mov r10, r3
	subs r3, #0x04
	ldm r3!, {r0}
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r2, [sp, #0x014]
	ldm r2!, {r1}
	str r2, [sp, #0x014]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r3, [sp, #0x010]
	ldm r3!, {r2}
	str r3, [sp, #0x010]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	str r5, [sp, #0x004]
	movs r4, #0x00
	str r4, [sp, #0x008]
	ldr r4, _080B5240 @ =0x09EF167C
	add r4, r9
	ldrh r4, [r4, #0x10]
	str r4, [sp, #0x00C]
	bl func_080023E0
	movs r0, #0x14
	add r9, r0
	adds r7, #0x02
	movs r1, #0x01
	negs r1, r1
	add r8, r1
	mov r2, r8
	cmp r2, #0x00
	bge _080B51CC
_080B522C:
	add sp, #0x018
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080B523C: .4byte 0x09EF180C
_080B5240: .4byte 0x09EF167C
.syntax divided
