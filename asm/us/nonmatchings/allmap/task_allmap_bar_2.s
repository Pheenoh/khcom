.syntax unified
	.align 2, 0
	.global task_allmap_bar_2
	.thumb
	.thumb_func
	.type task_allmap_bar_2, %function
task_allmap_bar_2: @ 080D418C
	push {r4, r5, r6, lr}
	add sp, #-0x010
	adds r6, r0, #0x0
	ldr r0, [r6, #0x28]
	cmp r0, #0x02
	beq _080D41F4
	ldr r0, [r6, #0x20]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r2, _080D41FC @ =0x0976D880
	ldr r3, [r6, #0x00]
	ldr r1, [r6, #0x08]
	str r1, [sp, #0x000]
	movs r5, #0x00
	str r5, [sp, #0x004]
	movs r4, #0xC0
	lsls r4, r4, #0x04
	str r4, [sp, #0x008]
	movs r1, #0xFA
	lsls r1, r1, #0x02
	str r1, [sp, #0x00C]
	movs r1, #0x00
	bl DrawSprite
	ldr r1, [r6, #0x10]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, _080D4200 @ =0x0976DB68
	ldr r3, [r6, #0x04]
	ldr r0, [r6, #0x08]
	str r0, [sp, #0x000]
	str r5, [sp, #0x004]
	str r4, [sp, #0x008]
	ldr r0, _080D4204 @ =0x000003E9
	str r0, [sp, #0x00C]
	movs r0, #0x80
	bl DrawSprite
	ldr r1, [r6, #0x18]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, _080D4208 @ =0x0976DB9C
	ldr r3, [r6, #0x04]
	ldr r0, [r6, #0x08]
	str r0, [sp, #0x000]
	str r5, [sp, #0x004]
	str r4, [sp, #0x008]
	ldr r0, _080D420C @ =0x000003EA
	str r0, [sp, #0x00C]
	movs r0, #0x80
	bl DrawSprite
_080D41F4:
	add sp, #0x010
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080D41FC: .4byte 0x0976D880
_080D4200: .4byte 0x0976DB68
_080D4204: .4byte 0x000003E9
_080D4208: .4byte 0x0976DB9C
_080D420C: .4byte 0x000003EA
.syntax divided
