.syntax unified
	.align 2, 0
	.global task_bos_md_3
	.thumb
	.thumb_func
	.type task_bos_md_3, %function
task_bos_md_3: @ 080FCA28
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0x0
	movs r0, #0x01
	bl func_0800501C
	adds r5, r7, #0x0
	adds r5, #0xA8
	adds r4, r7, #0x0
	adds r4, #0x68
	movs r6, #0x00
_080FCA44:
	adds r0, r5, #0x0
	bl func_08012304
	adds r0, r4, #0x0
	bl func_0801B7D8
	movs r0, #0x88
	lsls r0, r0, #0x01
	adds r5, r5, r0
	adds r4, r4, r0
	subs r6, #0x01
	cmp r6, #0x00
	bge _080FCA44
	movs r0, #0x2C
	adds r0, r0, r7
	mov r8, r0
	movs r0, #0x40
	adds r0, r0, r7
	mov r9, r0
	movs r0, #0x54
	adds r0, r0, r7
	mov r10, r0
	movs r4, #0x00
	movs r0, #0xBE
	lsls r0, r0, #0x01
	adds r5, r7, r0
	movs r6, #0x01
_080FCA7A:
	adds r0, r5, r4
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080FCA86
	bl func_080028C0
_080FCA86:
	adds r4, #0x14
	subs r6, #0x01
	cmp r6, #0x00
	bge _080FCA7A
	ldr r0, [r7, #0x20]
	bl func_08002C10
	ldr r0, [r7, #0x24]
	bl func_08002C10
	mov r0, r8
	bl func_08000F0C
	mov r0, r9
	bl func_08000F0C
	mov r0, r10
	bl func_08000F0C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
