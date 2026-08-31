.syntax unified
	.align 2, 0
	.global task_room_name_2
	.thumb
	.thumb_func
	.type task_room_name_2, %function
task_room_name_2: @ 080F7D44
	push {r4, r5, r6, lr}
	add sp, #-0x010
	adds r6, r0, #0x0
	adds r0, #0x28
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080F7DA6
	movs r1, #0x80
	lsls r1, r1, #0x01
	ldr r2, [r6, #0x1C]
	movs r0, #0x00
	movs r3, #0x00
	bl AllocObjAffine
	adds r5, r0, #0x0
	ldr r0, [r6, #0x14]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r1, [r6, #0x18]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, [r6, #0x08]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	str r5, [sp, #0x004]
	movs r4, #0x00
	str r4, [sp, #0x008]
	movs r4, #0x3C
	str r4, [sp, #0x00C]
	bl DrawSprite
	ldr r0, [r6, #0x0C]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r1, [r6, #0x10]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	adds r2, r6, #0x0
	adds r2, #0x3C
	ldr r3, [r6, #0x38]
	movs r4, #0x32
	str r4, [sp, #0x000]
	adds r4, r6, #0x0
	adds r4, #0x34
	ldrb r4, [r4, #0x00]
	str r4, [sp, #0x004]
	bl func_080664D8
_080F7DA6:
	add sp, #0x010
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
