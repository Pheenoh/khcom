.syntax unified
	.align 2, 0
	.global task_allmap_pusha_2
	.thumb
	.thumb_func
	.type task_allmap_pusha_2, %function
task_allmap_pusha_2: @ 080D4C88
	push {r4, r5, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	bl func_080D4D1C
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x00
	beq _080D4CA4
	adds r0, r4, #0x0
	adds r0, #0x14
	bl TaskPoolDraw
	b _080D4CE8
_080D4CA4:
	ldr r2, [r4, #0x0C]
	ldrh r1, [r2, #0x30]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	ldr r1, _080D4CF0 @ =0x0203C540
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	strh r0, [r4, #0x2C]
	ldrh r0, [r2, #0x32]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r0, _080D4CF4 @ =0x0203C53C
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	strh r1, [r4, #0x2E]
	movs r2, #0x2C
	ldsh r0, [r4, r2]
	ldrh r2, [r4, #0x12]
	subs r1, r1, r2
	adds r1, #0x02
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x00]
	ldr r4, [r4, #0x04]
	str r4, [sp, #0x000]
	str r5, [sp, #0x004]
	str r5, [sp, #0x008]
	movs r4, #0x30
	str r4, [sp, #0x00C]
	bl DrawSprite
_080D4CE8:
	add sp, #0x010
	pop {r4, r5}
	pop {r0}
	bx r0
_080D4CF0: .4byte 0x0203C540
_080D4CF4: .4byte 0x0203C53C
.syntax divided
